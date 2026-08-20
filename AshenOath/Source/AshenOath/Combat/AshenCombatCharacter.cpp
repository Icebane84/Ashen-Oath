// Copyright Phoenix Protocol. All rights reserved.

#include "AshenCombatCharacter.h"
#include "CombatEnemy.h"
#include "Components/CapsuleComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/Engine.h"
#include "AshenOath_InputBufferComponent.h"
#include "AshenOath_LockOnComponent.h"
#include "AshenOath_EquipmentComponent.h"
#include "AshenOath_StatsComponent.h"
#include "AshenOath_SanityComponent.h"
#include "AshenOath_ManifestationComponent.h"
#include "AshenOath_StaminaComponent.h"
#include "AshenOath_ManaComponent.h"
#include "AshenOath_PoiseComponent.h"
#include "AshenGameSettings.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Camera/PlayerCameraManager.h"
#include "TimerManager.h"
#include "AshenSanityPostProcessComponent.h"
#include "AshenOath_ImprintBufferComponent.h"
#include "AshenOath_OathRegistryComponent.h"
#include "AshenOath_CurrencyComponent.h"
#include "AshenOath_HealthComponent.h"
#include "AshenEmberEchoActor.h"
#include "AshenSoulConstellationSubsystem.h"
#include "AshenKernelDebugOverlay.h"
#include "Blueprint/UserWidget.h"
#include "UObject/ConstructorHelpers.h"




#include "Companions/AshenTrioPartySpawnerComponent.h"
#include "Components/SkeletalMeshComponent.h"

AAshenCombatCharacter::AAshenCombatCharacter()
{
	// Instantiate optional combat components to keep base character lightweight
	InputBufferComponent = CreateDefaultSubobject<UAshenOath_InputBufferComponent>(TEXT("InputBufferComponent"));
	LockOnComponent = CreateDefaultSubobject<UAshenOath_LockOnComponent>(TEXT("LockOnComponent"));
	EquipmentComponent = CreateDefaultSubobject<UAshenOath_EquipmentComponent>(TEXT("EquipmentComponent"));
	StatsComponent = CreateDefaultSubobject<UAshenOath_StatsComponent>(TEXT("StatsComponent"));
	SanityComponent = CreateDefaultSubobject<UAshenOath_SanityComponent>(TEXT("SanityComponent"));
	ManifestationComponent = CreateDefaultSubobject<UAshenOath_ManifestationComponent>(TEXT("ManifestationComponent"));
	StaminaComponent = CreateDefaultSubobject<UAshenOath_StaminaComponent>(TEXT("StaminaComponent"));
	ManaComponent = CreateDefaultSubobject<UAshenOath_ManaComponent>(TEXT("ManaComponent"));
	PoiseComponent = CreateDefaultSubobject<UAshenOath_PoiseComponent>(TEXT("PoiseComponent"));
	SanityPostProcessComponent = CreateDefaultSubobject<UAshenSanityPostProcessComponent>(TEXT("SanityPostProcessComponent"));
	ImprintBufferComponent = CreateDefaultSubobject<UAshenOath_ImprintBufferComponent>(TEXT("ImprintBufferComponent"));
	OathRegistryComponent = CreateDefaultSubobject<UAshenOath_OathRegistryComponent>(TEXT("OathRegistryComponent"));
	CurrencyComponent = CreateDefaultSubobject<UAshenOath_CurrencyComponent>(TEXT("CurrencyComponent"));
	TrioPartySpawnerComponent = CreateDefaultSubobject<UAshenTrioPartySpawnerComponent>(TEXT("TrioPartySpawnerComponent"));



	// Load and assign Kaelen's Skeletal Mesh dynamically
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> KaelenMeshAsset(
		TEXT("/Game/Characters/Kaelen/Mesh/Meshy_AI_Anatomy_of_a_Paladin__0710002240_texture.Meshy_AI_Anatomy_of_a_Paladin__0710002240_texture")
	);

	if (KaelenMeshAsset.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(KaelenMeshAsset.Object);
		// Align the mesh inside the capsule (oriented forward along the capsule's X axis)
		GetMesh()->SetRelativeLocation(FVector(0.0f, 0.0f, -90.0f));
		GetMesh()->SetRelativeRotation(FRotator(0.0f, -90.0f, 0.0f));
	}
}

UAshenOath_EquipmentComponent* AAshenCombatCharacter::GetEquipmentComponent_Implementation() const
{
	return EquipmentComponent;
}

UAshenOath_StatsComponent* AAshenCombatCharacter::GetStatsComponent_Implementation() const
{
	return StatsComponent;
}

UAshenOath_SanityComponent* AAshenCombatCharacter::GetSanityComponent_Implementation() const
{
	return SanityComponent;
}

UAshenOath_StaminaComponent* AAshenCombatCharacter::GetStaminaComponent_Implementation() const
{
	return StaminaComponent;
}

UAshenOath_ManaComponent* AAshenCombatCharacter::GetManaComponent_Implementation() const
{
	return ManaComponent;
}

UAshenOath_PoiseComponent* AAshenCombatCharacter::GetPoiseComponent_Implementation() const
{
	return PoiseComponent;
}

UAshenOath_InputBufferComponent* AAshenCombatCharacter::GetInputBufferComponent() const
{
	return InputBufferComponent;
}

void AAshenCombatCharacter::BeginPlay()
{
	Super::BeginPlay();

	// Load configuration-driven settings
	if (const UAshenGameSettings* Settings = GetDefault<UAshenGameSettings>())
	{
		CorruptionTransitionSpeed = Settings->CorruptionTransitionSpeed;
	}

	if (GetCharacterMovement())
	{
		BaseWalkSpeed = GetCharacterMovement()->MaxWalkSpeed;
	}
	CurrentFOV = NormalFOV;

	// Automatically spawn UAshenKernelDebugOverlay for real-time PIE visual feedback
	if (IsLocallyControlled())
	{
		if (APlayerController* PC = Cast<APlayerController>(GetController()))
		{
			UAshenKernelDebugOverlay* DebugOverlay = CreateWidget<UAshenKernelDebugOverlay>(PC, UAshenKernelDebugOverlay::StaticClass());
			if (DebugOverlay)
			{
				DebugOverlay->AddToViewport(999);
				UE_LOG(LogTemp, Log, TEXT("AAshenCombatCharacter: Automatically spawned UAshenKernelDebugOverlay onto viewport."));
			}
		}
	}

	// Bind death delegate
	if (UAshenOath_HealthComponent* Health = IAshenCharacterInterface::Execute_GetHealthComponent(this))
	{
		Health->OnDied.AddDynamic(this, &AAshenCombatCharacter::HandleCharacterDeath);

		// Bind the crisis health watcher — fires OnDevilsBargainCrisisEntered once per life
		Health->OnHealthChanged.AddDynamic(this, &AAshenCombatCharacter::HandleHealthChanged);
	}

	if (UCapsuleComponent* Capsule = GetCapsuleComponent())
	{
		Capsule->SetGenerateOverlapEvents(true);
		Capsule->OnComponentBeginOverlap.AddDynamic(this, &AAshenCombatCharacter::OnPlayerCapsuleOverlap);
	}

	// Create dynamic instances for all material slots on Kaelen's mesh to allow runtime parameter tweaking


	if (USkeletalMeshComponent* MeshComp = GetMesh())
	{
		const int32 NumMaterials = MeshComp->GetNumMaterials();
		for (int32 i = 0; i < NumMaterials; ++i)
		{
			UMaterialInstanceDynamic* MID = MeshComp->CreateAndSetMaterialInstanceDynamic(i);
			if (MID)
			{
				DynamicMaterials.Add(MID);
			}
		}
	}
}

void AAshenCombatCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	// Smoothly interpolate current corruption value to target state (FMath::FInterpTo)
	if (!FMath::IsNearlyEqual(CorruptionAmount, TargetCorruptionAmount, 0.001f))
	{
		CorruptionAmount = FMath::FInterpTo(CorruptionAmount, TargetCorruptionAmount, DeltaSeconds, CorruptionTransitionSpeed);

		// Update scalar parameter inside all dynamic material instances
		for (UMaterialInstanceDynamic* MID : DynamicMaterials)
		{
			if (MID)
			{
				MID->SetScalarParameterValue(TEXT("CorruptionAmount"), CorruptionAmount);
			}
		}

		// Apply/remove Berserker state modifiers based on corruption target transition
		if (CorruptionAmount >= 0.7f && TargetCorruptionAmount == 1.0f)
		{
			ApplyBerserkerState(true);
		}
		else if (CorruptionAmount < 0.7f && TargetCorruptionAmount == 0.0f)
		{
			ApplyBerserkerState(false);
		}
	}

	// If in Berserker/Dark state, apply active sanity decay and adjust FOV
	if (CorruptionAmount >= 0.7f)
	{
		// Draining sanity exponentially over time (12.0f units scaled by corruption curve)
		if (UAshenOath_SanityComponent* Sanity = IAshenCharacterInterface::Execute_GetSanityComponent(this))
		{
			float SanityDrain = 12.0f * CorruptionAmount * DeltaSeconds;
			Sanity->SufferMentalDamage(SanityDrain);
		}

		// Lerp camera FOV down to compressed Berserker field
		CurrentFOV = FMath::FInterpTo(CurrentFOV, BerserkerFOV, DeltaSeconds, 5.0f);
	}
	else
	{
		// Restore normal camera FOV
		CurrentFOV = FMath::FInterpTo(CurrentFOV, NormalFOV, DeltaSeconds, 5.0f);
	}

	// Push FOV updates to Camera Manager
	if (APlayerController* PC = Cast<APlayerController>(GetController()))
	{
		if (PC->PlayerCameraManager)
		{
			PC->PlayerCameraManager->SetFOV(CurrentFOV);
		}
	}
}

void AAshenCombatCharacter::TransitionCorruptionState(bool bBecomeDarkState)
{
	TargetCorruptionAmount = bBecomeDarkState ? 1.0f : 0.0f;
}

void AAshenCombatCharacter::HandleHealthChanged(float CurrentHealth, float MaxHealth)
{
	// Guard: only fire once per life and only while alive
	if (bCrisisTriggeredThisLife) return;
	if (MaxHealth <= 0.f || CurrentHealth <= 0.f) return;

	const float HealthPercent = CurrentHealth / MaxHealth;
	if (HealthPercent <= DevilsBargainHealthThreshold)
	{
		bCrisisTriggeredThisLife = true;

		UE_LOG(LogTemp, Warning, TEXT("AAshenCombatCharacter: ====================================================="));
		UE_LOG(LogTemp, Warning, TEXT("AAshenCombatCharacter: DEVIL'S BARGAIN WINDOW OPEN — HP %.1f%% (<= %.1f%%)"),
			HealthPercent * 100.f, DevilsBargainHealthThreshold * 100.f);
		UE_LOG(LogTemp, Warning, TEXT("AAshenCombatCharacter: ====================================================="));

		// 1. Native C++ Time Dilation Slow-Motion (0.1x)
		UGameplayStatics::SetGlobalTimeDilation(GetWorld(), 0.1f);

		// 2. Native C++ On-Screen Alert Message
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("⚠ DEVIL'S BARGAIN ACTIVATED — CRITICAL HEALTH!"));
		}

		// 3. Set 5-second timer to restore normal speed (1.0x)
		GetWorldTimerManager().SetTimer(DevilsBargainTimerHandle, this, &AAshenCombatCharacter::ResetDevilsBargainTimeDilation, 0.5f, false); // 0.5s real-world time at 0.1x dilation = 5s game time

		// 4. Broadcast delegate for any Blueprint listeners
		OnDevilsBargainCrisisEntered.Broadcast();
	}
}

void AAshenCombatCharacter::ResetDevilsBargainTimeDilation()
{
	UGameplayStatics::SetGlobalTimeDilation(GetWorld(), 1.0f);
	UE_LOG(LogTemp, Warning, TEXT("AAshenCombatCharacter: Devil's Bargain time dilation reset to 1.0."));
}

void AAshenCombatCharacter::OnPlayerCapsuleOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// Passive overlap damage disabled here so enemies don't die instantly on body contact
}

void AAshenCombatCharacter::ApplyBerserkerState(bool bActive)
{
	if (UAshenOath_PoiseComponent* Poise = IAshenCharacterInterface::Execute_GetPoiseComponent(this))
	{
		Poise->SetHyperArmorActive(bActive);
	}

	if (GetCharacterMovement())
	{
		GetCharacterMovement()->MaxWalkSpeed = bActive ? (BaseWalkSpeed * 1.5f) : BaseWalkSpeed;
	}
}

void AAshenCombatCharacter::TriggerStrikeImpact()
{
	UWorld* World = GetWorld();
	if (World && !HitStopTimerHandle.IsValid())
	{
		// Apply hitstop dilation freeze
		UGameplayStatics::SetGlobalTimeDilation(World, HitStopDilation);

		// Compress camera FOV elastically (sudden lens snap)
		CurrentFOV = BerserkerFOV - 12.0f;

		// Timer to reset dilation
		World->GetTimerManager().SetTimer(
			HitStopTimerHandle,
			this,
			&AAshenCombatCharacter::ResetHitStop,
			0.08f * HitStopDilation,
			false
		);
	}
}

void AAshenCombatCharacter::ResetHitStop()
{
	UWorld* World = GetWorld();
	if (World)
	{
		UGameplayStatics::SetGlobalTimeDilation(World, 1.0f);
	}
	HitStopTimerHandle.Invalidate();
}

void AAshenCombatCharacter::HandleCharacterDeath()
{
	UE_LOG(LogTemp, Warning, TEXT("AAshenCombatCharacter: Player died! Executing Soulslike death & respawn pipeline."));

	// Reset crisis guard — next life gets a fresh Devil's Bargain window
	bCrisisTriggeredThisLife = false;

	// 1. Drop Embers & spawn Ember Echo actor at death position
	float LostEmbers = 0.0f;
	if (CurrencyComponent)
	{
		LostEmbers = CurrencyComponent->DropEmbersOnDeath();
	}

	if (GetWorld() && LostEmbers > 0.0f)
	{
		FActorSpawnParameters SpawnParams;
		SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
		if (AAshenEmberEchoActor* Echo = GetWorld()->SpawnActor<AAshenEmberEchoActor>(AAshenEmberEchoActor::StaticClass(), GetActorLocation(), GetActorRotation(), SpawnParams))
		{
			Echo->SetStoredEmbers(LostEmbers);
			UE_LOG(LogTemp, Log, TEXT("AAshenCombatCharacter: Spawned Ember Echo holding %.1f Embers."), LostEmbers);
		}
	}

	// 2. Decay/wipe unresolved imprint buffer
	if (ImprintBufferComponent)
	{
		ImprintBufferComponent->DecayBuffer();
	}

	// 3. Increment global Despair accumulator
	if (UGameInstance* GI = GetGameInstance())
	{
		if (UAshenSoulConstellationSubsystem* Kernel = GI->GetSubsystem<UAshenSoulConstellationSubsystem>())
		{
			Kernel->ApplyDespairOnDeath(0.15f);
		}
	}


	// 4. Refill health & resources and respawn at Sanctuary checkpoint
	if (UAshenOath_HealthComponent* Health = IAshenCharacterInterface::Execute_GetHealthComponent(this))
	{
		Health->Heal(Health->GetMaxHealth());
	}

	SetActorLocation(SpawnPosition);
	UE_LOG(LogTemp, Log, TEXT("AAshenCombatCharacter: Player respawned at Sanctuary checkpoint position."));
}
