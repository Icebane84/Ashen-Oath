// Copyright Epic Games, Inc. All Rights Reserved.

#include "AshenOathCharacter.h"
#include "Engine/LocalPlayer.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/Engine.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/Controller.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include "AshenOath.h"
#include "AshenOath_HealthComponent.h"
#include "AshenOath_HurtboxComponent.h"
#include "AshenOath_InputBufferComponent.h"
#include "AshenOath_LockOnComponent.h"
#include "AshenOath_EquipmentComponent.h"
#include "AshenOath_InventoryComponent.h"
#include "AshenOath_StatsComponent.h"
#include "AshenOath_SanityComponent.h"
#include "AshenOath_ManifestationComponent.h"
#include "AshenOath_StaminaComponent.h"
#include "AshenOath_ManaComponent.h"
#include "AshenOath_PoiseComponent.h"
#include "AshenInteractionComponent.h"
#include "AshenDamageTextPool.h"
#include "AshenOath_DirectorSubsystem.h"
#include "AshenOath_GameEventSubsystem.h"
#include "AshenOath_AbilitySystemComponent.h"
#include "AshenAttributeSet.h"
#include "AshenGameSettings.h"

AAshenOathCharacter::AAshenOathCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);
		
	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f);

	// Note: For faster iteration times these variables, and many more, can be tweaked in the Character Blueprint
	// instead of recompiling to adjust them
	GetCharacterMovement()->JumpZVelocity = 500.f;
	GetCharacterMovement()->AirControl = 0.35f;
	GetCharacterMovement()->MaxWalkSpeed = 500.f;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;
	GetCharacterMovement()->BrakingDecelerationFalling = 1500.0f;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 400.0f;
	CameraBoom->bUsePawnControlRotation = true;

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named ThirdPersonCharacter (to avoid direct content references in C++)

	// Create health and hurtbox components
	HealthComponent = CreateDefaultSubobject<UAshenOath_HealthComponent>(TEXT("HealthComponent"));
	
	HurtboxComponent = CreateDefaultSubobject<UAshenOath_HurtboxComponent>(TEXT("HurtboxComponent"));
	HurtboxComponent->SetupAttachment(RootComponent);
	HurtboxComponent->SetTeamId(0); // Player team is 0

	// Instantiate Inventory Component
	InventoryComponent = CreateDefaultSubobject<UAshenOath_InventoryComponent>(TEXT("InventoryComponent"));

	// Instantiate Damage Text Pool
	DamageTextPool = CreateDefaultSubobject<UAshenDamageTextPool>(TEXT("DamageTextPool"));

	// Instantiate Interaction Component
	InteractionComponent = CreateDefaultSubobject<UAshenInteractionComponent>(TEXT("InteractionComponent"));

	// Create Ability System Component
	AbilitySystemComponent = CreateDefaultSubobject<UAshenAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);

	AttributeSet = CreateDefaultSubobject<UAshenAttributeSet>(TEXT("AttributeSet"));
	// Default States
	bIsDodging = false;
	bIsSprinting = false;

	// Camera & Screen Shake Settings
	NormalFOV = 75.0f;
	SprintFOV = 85.0f;
	FOVSmoothSpeed = 10.0f;
	TraumaDecay = 2.0f;
	MaxYawShake = 5.0f;
	MaxPitchShake = 5.0f;
	CameraTrauma = 0.0f;
}

void AAshenOathCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent)) {
		
		// Jumping
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &ACharacter::Jump);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);

		// Moving
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AAshenOathCharacter::Move);
		EnhancedInputComponent->BindAction(MouseLookAction, ETriggerEvent::Triggered, this, &AAshenOathCharacter::Look);

		// Looking
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AAshenOathCharacter::Look);

		// Attacking
		EnhancedInputComponent->BindAction(AttackAction, ETriggerEvent::Started, this, &AAshenOathCharacter::Attack);

		// Dodging
		EnhancedInputComponent->BindAction(DodgeAction, ETriggerEvent::Started, this, &AAshenOathCharacter::Dodge);

		// Sprinting
		EnhancedInputComponent->BindAction(SprintAction, ETriggerEvent::Started, this, &AAshenOathCharacter::StartSprint);
		EnhancedInputComponent->BindAction(SprintAction, ETriggerEvent::Completed, this, &AAshenOathCharacter::StopSprint);

		// Interacting
		EnhancedInputComponent->BindAction(InteractAction, ETriggerEvent::Started, this, &AAshenOathCharacter::Interact);
	}
	else
	{
		UE_LOG(LogAshenOath, Error, TEXT("'%s' Failed to find an Enhanced Input component! This template is built to use the Enhanced Input system. If you intend to use the legacy system, then you will need to update this C++ file."), *GetNameSafe(this));
	}
}

void AAshenOathCharacter::Move(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D MovementVector = Value.Get<FVector2D>();

	// route the input
	DoMove(MovementVector.X, MovementVector.Y);
}

void AAshenOathCharacter::Look(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	// route the input
	DoLook(LookAxisVector.X, LookAxisVector.Y);
}

void AAshenOathCharacter::DoMove(float Right, float Forward)
{
	if (GetController() != nullptr)
	{
		// find out which way is forward
		const FRotator Rotation = GetController()->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);

		// get right vector 
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		// add movement 
		AddMovementInput(ForwardDirection, Forward);
		AddMovementInput(RightDirection, Right);
	}
}

void AAshenOathCharacter::DoLook(float Yaw, float Pitch)
{
	if (GetController() != nullptr)
	{
		// add yaw and pitch input to controller
		AddControllerYawInput(Yaw);
		AddControllerPitchInput(Pitch);
	}
}

void AAshenOathCharacter::DoJumpStart()
{
	// signal the character to jump
	Jump();
}

void AAshenOathCharacter::DoJumpEnd()
{
	// signal the character to stop jumping
	StopJumping();
}

void AAshenOathCharacter::Attack()
{
	UAnimInstance* AnimInstance = GetMesh()->GetAnimInstance();
	if (AnimInstance && AttackMontage && !AnimInstance->Montage_IsPlaying(AttackMontage))
	{
		AnimInstance->Montage_Play(AttackMontage);
	}
}

void AAshenOathCharacter::Dodge()
{
	// Queue the action to the InputBufferComponent first
	if (UAshenOath_InputBufferComponent* InputBuffer = GetInputBufferComponent())
	{
		InputBuffer->BufferInput(TEXT("Dodge"), true);
	}

	DoDodge();
}

void AAshenOathCharacter::StartSprint()
{
	if (UAshenOath_InputBufferComponent* InputBuffer = GetInputBufferComponent())
	{
		InputBuffer->BufferInput(TEXT("Sprint"), true);
	}

	DoSprintStart();
}

void AAshenOathCharacter::StopSprint()
{
	if (UAshenOath_InputBufferComponent* InputBuffer = GetInputBufferComponent())
	{
		InputBuffer->BufferInput(TEXT("Sprint"), false);
	}

	DoSprintEnd();
}

void AAshenOathCharacter::DoDodge()
{
	// Consume from input buffer if we are acting on it
	if (UAshenOath_InputBufferComponent* InputBuffer = GetInputBufferComponent())
	{
		InputBuffer->ConsumeBufferedAction(TEXT("Dodge"));
	}

	if (bIsDodging)
	{
		return;
	}

	// Query settings for dodge forces and stamina costs
	float DodgeForce = 1500.0f;
	float DodgeDuration = 0.4f;
	float DodgeStaminaCost = 20.0f;
	if (const UAshenGameSettings* Settings = GetDefault<UAshenGameSettings>())
	{
		DodgeForce = Settings->BaseDodgeForce;
		DodgeDuration = Settings->BaseDodgeDuration;
		DodgeStaminaCost = Settings->BaseDodgeStaminaCost;
	}

	// 1. Stamina Gating & Consumption
	if (UAshenOath_StaminaComponent* StaminaComp = FindComponentByClass<UAshenOath_StaminaComponent>())
	{
		if (StaminaComp->GetCurrentStamina() < DodgeStaminaCost)
		{
			// Insufficient stamina for dodge roll
			return;
		}
		StaminaComp->ConsumeStamina(DodgeStaminaCost);
	}

	bIsDodging = true;
	
	// Broadcast delegate matching dodge_started signal
	if (OnDodgeStarted.IsBound())
	{
		OnDodgeStarted.Broadcast();
	}

	// 2. Direction Calculation with Lock-On Orbital Strafe Support
	FVector DodgeDirection = FVector::ZeroVector;
	FVector InputVector = GetLastMovementInputVector().GetSafeNormal2D();

	UAshenOath_LockOnComponent* LockOnComp = FindComponentByClass<UAshenOath_LockOnComponent>();
	if (LockOnComp && LockOnComp->IsLockedOn() && LockOnComp->GetLockedTarget())
	{
		AActor* LockedTarget = LockOnComp->GetLockedTarget();
		FVector ToTarget = (LockedTarget->GetActorLocation() - GetActorLocation()).GetSafeNormal2D();
		FVector TangentRight = FVector(-ToTarget.Y, ToTarget.X, 0.0f); // 90 degrees clockwise

		if (InputVector.IsNearlyZero())
		{
			// Default to backward hop away from locked target
			DodgeDirection = -ToTarget;
		}
		else
		{
			// Orbital Strafe: Project player input onto Target Radial (Forward/Back) and Tangent (Left/Right Orbit) axes
			float RadialDot = FVector::DotProduct(InputVector, ToTarget);
			float LateralDot = FVector::DotProduct(InputVector, TangentRight);

			// Synthesize orbital flank dodge vector
			DodgeDirection = (ToTarget * RadialDot + TangentRight * LateralDot).GetSafeNormal2D();
		}
	}
	else
	{
		// Free-aim directional dodge
		DodgeDirection = InputVector;
		if (DodgeDirection.IsNearlyZero())
		{
			DodgeDirection = -GetActorForwardVector().GetSafeNormal2D(); // fallback to backward dodge
		}
	}

	// Snap rotation to face direction
	if (!DodgeDirection.IsNearlyZero())
	{
		FRotator NewRotation = FRotationMatrix::MakeFromX(DodgeDirection).Rotator();
		NewRotation.Pitch = 0.0f;
		NewRotation.Roll = 0.0f;
		SetActorRotation(NewRotation);
	}

	// Launch Character
	LaunchCharacter(DodgeDirection * DodgeForce, true, true);

	// Set timer to end dodge after duration
	GetWorldTimerManager().SetTimer(
		DodgeTimerHandle,
		this,
		&AAshenOathCharacter::EndDodge,
		DodgeDuration,
		false
	);
}

void AAshenOathCharacter::EndDodge()
{
	bIsDodging = false;
}

void AAshenOathCharacter::DoSprintStart()
{
	if (!bIsSprinting)
	{
		bIsSprinting = true;
		if (OnSprintStarted.IsBound())
		{
			OnSprintStarted.Broadcast();
		}
	}
}

void AAshenOathCharacter::DoSprintEnd()
{
	if (bIsSprinting)
	{
		bIsSprinting = false;
	}
}

void AAshenOathCharacter::BeginPlay()
{
	Super::BeginPlay();

	// Load configuration-driven settings
	if (const UAshenGameSettings* Settings = GetDefault<UAshenGameSettings>())
	{
		NormalFOV = Settings->BaseNormalFOV;
		SprintFOV = Settings->BaseSprintFOV;
		FOVSmoothSpeed = Settings->BaseFOVSmoothSpeed;
		TraumaDecay = Settings->BaseTraumaDecay;
	}

	SpawnPosition = GetActorLocation();

	// Register player character with the Director Subsystem
	if (UGameInstance* GameInstance = GetGameInstance())
	{
		if (UAshenOath_DirectorSubsystem* Director = GameInstance->GetSubsystem<UAshenOath_DirectorSubsystem>())
		{
			Director->SetPlayerPawn(this);
		}

		if (HealthComponent)
		{
			HealthComponent->OnDied.AddDynamic(this, &AAshenOathCharacter::HandlePlayerDied);
			HealthComponent->OnDamaged.AddDynamic(this, &AAshenOathCharacter::HandlePlayerDamaged);
		}

		if (UAshenOath_PoiseComponent* Poise = IAshenCharacterInterface::Execute_GetPoiseComponent(this))
		{
			Poise->OnPostureBroken.AddDynamic(this, &AAshenOathCharacter::HandlePostureBroken);
		}

		if (HurtboxComponent)
		{
			HurtboxComponent->OnParryTriggered.AddDynamic(this, &AAshenOathCharacter::HandleParryTriggered);
		}
	}
}

void AAshenOathCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	// Server-side GAS initialization
	if (AbilitySystemComponent)
	{
		AbilitySystemComponent->InitAbilityActorInfo(this, this);
	}
}

void AAshenOathCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	// Client-side GAS initialization
	if (AbilitySystemComponent)
	{
		AbilitySystemComponent->InitAbilityActorInfo(this, this);
	}
}

void AAshenOathCharacter::HandlePlayerDied()
{
	if (UGameInstance* GameInstance = GetGameInstance())
	{
		if (UAshenOath_GameEventSubsystem* GameEvents = GameInstance->GetSubsystem<UAshenOath_GameEventSubsystem>())
		{
			GameEvents->BroadcastPlayerDied();
		}
	}
}

UAshenOath_HealthComponent* AAshenOathCharacter::GetHealthComponent_Implementation() const
{
	return HealthComponent;
}

UAbilitySystemComponent* AAshenOathCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void AAshenOathCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if (UAshenOath_LockOnComponent* LockOn = FindComponentByClass<UAshenOath_LockOnComponent>())
	{
		LockOn->UpdateLockOnRotation(DeltaSeconds);
	}

	// 1. Dynamic FOV blend (Adrenaline effect)
	if (FollowCamera)
	{
		float TargetFOV = (bIsSprinting || bIsDodging) ? SprintFOV : NormalFOV;
		FollowCamera->FieldOfView = FMath::FInterpTo(FollowCamera->FieldOfView, TargetFOV, DeltaSeconds, FOVSmoothSpeed);
	}

	// 2. Screenshake / Decaying Trauma process
	if (CameraTrauma > 0.0f)
	{
		CameraTrauma = FMath::Max(CameraTrauma - TraumaDecay * DeltaSeconds, 0.0f);
		float Shake = CameraTrauma * CameraTrauma;
		float PitchOffset = FMath::FRandRange(-MaxPitchShake, MaxPitchShake) * Shake;
		float YawOffset = FMath::FRandRange(-MaxYawShake, MaxYawShake) * Shake;

		if (FollowCamera)
		{
			FollowCamera->SetRelativeRotation(FRotator(PitchOffset, YawOffset, 0.0f));
		}
	}
	else
	{
		if (FollowCamera)
		{
			FollowCamera->SetRelativeRotation(FRotator::ZeroRotator);
		}
	}
}

UAshenOath_EquipmentComponent* AAshenOathCharacter::GetEquipmentComponent_Implementation() const
{
	return nullptr;
}

UAshenOath_InventoryComponent* AAshenOathCharacter::GetInventoryComponent_Implementation() const
{
	return InventoryComponent;
}

UAshenOath_StatsComponent* AAshenOathCharacter::GetStatsComponent_Implementation() const
{
	return nullptr;
}

UAshenOath_SanityComponent* AAshenOathCharacter::GetSanityComponent_Implementation() const
{
	return nullptr;
}

UAshenOath_StaminaComponent* AAshenOathCharacter::GetStaminaComponent_Implementation() const
{
	return nullptr;
}

UAshenOath_ManaComponent* AAshenOathCharacter::GetManaComponent_Implementation() const
{
	return nullptr;
}

UAshenOath_PoiseComponent* AAshenOathCharacter::GetPoiseComponent_Implementation() const
{
	return nullptr;
}

void AAshenOathCharacter::ApplyCameraTrauma(float Amount)
{
	float FinalAmount = Amount * GetDefault<UAshenGameSettings>()->CameraTraumaMultiplier;
	CameraTrauma = FMath::Clamp(CameraTrauma + FinalAmount, 0.0f, 1.0f);
}

void AAshenOathCharacter::HandlePlayerDamaged(float Amount, AActor* DamageSource)
{
	float TraumaAmt = 0.4f;
	if (const UAshenGameSettings* Settings = GetDefault<UAshenGameSettings>())
	{
		TraumaAmt = Settings->DamageTraumaAmount;
	}

	ApplyCameraTrauma(TraumaAmt);

	if (HealthComponent)
	{
		const float Percent = HealthComponent->GetHealthPercent();
		UE_LOG(LogTemp, Warning, TEXT("AAshenOathCharacter: Player took %.1f damage! Current HP: %.1f / %.1f (%.1f%%)"),
			Amount, HealthComponent->GetCurrentHealth(), HealthComponent->GetMaxHealth(), Percent * 100.f);

		// Devil's Bargain Crisis Trigger at <= 25% HP
		if (Percent <= 0.25f && Percent > 0.0f)
		{
			UE_LOG(LogTemp, Warning, TEXT("AAshenOathCharacter: DEVIL'S BARGAIN CRISIS ACTIVATED VIA DAMAGE!"));
			UGameplayStatics::SetGlobalTimeDilation(GetWorld(), 0.1f);
			if (GEngine)
			{
				GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("⚠ DEVIL'S BARGAIN ACTIVATED — CRITICAL HEALTH!"));
			}
		}
	}
}

void AAshenOathCharacter::Interact()
{
	if (InteractionComponent)
	{
		InteractionComponent->TriggerInteraction();
	}
}

void AAshenOathCharacter::HandlePostureBroken()
{
	// Disable player movement
	GetCharacterMovement()->DisableMovement();
	GetCharacterMovement()->Velocity = FVector::ZeroVector;

	// Play player stagger montage
	if (UAnimInstance* AnimInstance = GetMesh()->GetAnimInstance())
	{
		AnimInstance->Montage_Stop(0.2f);
		if (StaggerMontage)
		{
			AnimInstance->Montage_Play(StaggerMontage);
		}
	}

	// Trigger Reset Timer
	FTimerHandle StaggerResetTimer;
	GetWorld()->GetTimerManager().SetTimer(StaggerResetTimer, this, &AAshenOathCharacter::ResetStagger, 1.5f, false);
}

void AAshenOathCharacter::HandleParryTriggered(AActor* Attacker)
{
	if (Attacker && Attacker->Implements<UAshenCharacterInterface>())
	{
		UAshenOath_PoiseComponent* AttackerPoise = IAshenCharacterInterface::Execute_GetPoiseComponent(Attacker);
		if (AttackerPoise)
		{
			// Setting poise to 0.0f will immediately break the attacker's posture and stagger them!
			AttackerPoise->SetCurrentPoise(0.0f);
		}
	}
}

void AAshenOathCharacter::ResetStagger()
{
	if (HealthComponent && HealthComponent->GetCurrentHealth() > 0.0f)
	{
		GetCharacterMovement()->SetMovementMode(MOVE_Walking);
		if (UAshenOath_PoiseComponent* Poise = IAshenCharacterInterface::Execute_GetPoiseComponent(this))
		{
			Poise->ResetPoise();
		}
	}
}
