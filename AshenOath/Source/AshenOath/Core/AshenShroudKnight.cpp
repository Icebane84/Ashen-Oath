// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "AshenShroudKnight.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/CapsuleComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Engine/World.h"
#include "Engine/OverlapResult.h"
#include "TimerManager.h"

AAshenShroudKnight::AAshenShroudKnight()
{
	PrimaryActorTick.bCanEverTick = true;

	// Enforce default character mesh setup for Greywatch commander armor
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);
	GetCapsuleComponent()->SetCollisionProfileName(TEXT("Pawn"));

	// Shroud-Knight is highly agile but moves in jagged, phantom-like strides
	GetCharacterMovement()->MaxWalkSpeed = 480.0f;
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 360.0f, 0.0f);

	CurrentState = EShroudKnightState::Idle;
	bIsPhasing = false;
	bIsWarping = false;
	PhaseDurationTracker = 0.0f;
	PhaseCooldownTracker = 0.0f;
	WarpAlpha = 0.0f;
}

void AAshenShroudKnight::BeginPlay()
{
	Super::BeginPlay();

	// Cache dynamic materials across all rusted armor plate slots to drive dithered opacity/translucency
	if (USkeletalMeshComponent* CharacterMesh = GetMesh())
	{
		int32 NumMaterials = CharacterMesh->GetNumMaterials();
		for (int32 i = 0; i < NumMaterials; ++i)
		{
			UMaterialInterface* BaseMat = CharacterMesh->GetMaterial(i);
			if (BaseMat)
			{
				UMaterialInstanceDynamic* DynMat = CharacterMesh->CreateDynamicMaterialInstance(i, BaseMat);
				if (DynMat)
				{
					DynMaterials.Add(DynMat);
				}
			}
		}
	}

	// Set initial material variables (Start physical, full opacity)
	UpdateMaterialEtherealness(0.0f);
}

void AAshenShroudKnight::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Handle Active Phasing Duration
	if (bIsPhasing)
	{
		PhaseDurationTracker += DeltaTime;
		
		// Material flickering animation while in spectral phase
		float FlickerVal = 0.6f + FMath::Sin(GetWorld()->GetTimeSeconds() * 12.0f) * 0.15f;
		UpdateMaterialEtherealness(FlickerVal);

		if (PhaseDurationTracker >= MaxPhaseDuration)
		{
			// Verify if safe to materialize, if inside stone, prolong slightly
			if (!IsOverlappingStone())
			{
				TerminatePhaseShift(false);
			}
		}
	}
	else
	{
		if (PhaseCooldownTracker > 0.0f)
		{
			PhaseCooldownTracker -= DeltaTime;
		}
	}

	// Handle Active Warp-Strike Interp
	if (bIsWarping && ActiveTarget)
	{
		WarpAlpha += DeltaTime * (WarpStrikeSpeed / FVector::Dist(WarpStartPos, WarpEndPos));
		if (WarpAlpha >= 1.0f)
		{
			CompleteWarpStrike();
		}
		else
		{
			FVector CurrentPos = FMath::Lerp(WarpStartPos, WarpEndPos, WarpAlpha);
			SetActorLocation(CurrentPos, true);
		}
	}

	// Handle Creeping Paranoia UI and DoT Ticks
	UpdateCreepingParanoia(DeltaTime);
}

void AAshenShroudKnight::SetAIState(EShroudKnightState NewState)
{
	if (CurrentState == EShroudKnightState::ConsecratedStun && NewState != EShroudKnightState::Idle)
	{
		// Cannot escape stun until recovery timer completes
		return;
	}

	CurrentState = NewState;
}

void AAshenShroudKnight::InitiatePhaseShift()
{
	if (bIsPhasing || PhaseCooldownTracker > 0.0f || CurrentState == EShroudKnightState::ConsecratedStun)
	{
		return;
	}

	bIsPhasing = true;
	PhaseDurationTracker = 0.0f;
	SetAIState(EShroudKnightState::SpectralPhasing);

	// Switch capsule collision to ShroudPhasing profile to ignore Static/Stone colliders
	// while keeping Pawn-level overlap detections active for tracking players.
	GetCapsuleComponent()->SetCollisionProfileName(TEXT("ShroudPhasing"));

	// Instantly transition material parameter for shader to trigger dithered mask rendering
	UpdateMaterialEtherealness(0.7f);
}

void AAshenShroudKnight::TerminatePhaseShift(bool bForceSolid)
{
	if (!bIsPhasing)
	{
		return;
	}

	// If bForceSolid is true (e.g. Serafina's Consecration Anchor), bypass the check and force snap
	if (!bForceSolid && IsOverlappingStone())
	{
		// Shroud-Knight cannot solidify inside stone walls, push duration
		return;
	}

	bIsPhasing = false;
	PhaseCooldownTracker = PhaseCooldown;
	GetCapsuleComponent()->SetCollisionProfileName(TEXT("Pawn"));

	UpdateMaterialEtherealness(0.0f);

	if (CurrentState == EShroudKnightState::SpectralPhasing)
	{
		SetAIState(EShroudKnightState::Stalking);
	}
}

void AAshenShroudKnight::ExecuteWarpStrike(AActor* TargetActor)
{
	if (!TargetActor || bIsWarping || CurrentState == EShroudKnightState::ConsecratedStun)
	{
		return;
	}

	ActiveTarget = TargetActor;
	WarpStartPos = GetActorLocation();
	
	// Project end position slightly behind the target for an ambush strike
	FVector TargetForward = TargetActor->GetActorForwardVector();
	WarpEndPos = TargetActor->GetActorLocation() - (TargetForward * 120.0f);

	bIsWarping = true;
	WarpAlpha = 0.0f;
	SetAIState(EShroudKnightState::WarpStriking);

	// Toggle temporary dither transparency during movement
	UpdateMaterialEtherealness(0.95f);
}

void AAshenShroudKnight::CompleteWarpStrike()
{
	bIsWarping = false;
	SetAIState(EShroudKnightState::Stalking);
	UpdateMaterialEtherealness(0.0f);

	if (ActiveTarget)
	{
		float Distance = FVector::Dist(GetActorLocation(), ActiveTarget->GetActorLocation());
		if (Distance <= 250.0f) // Melee strike threshold
		{
			// Apply damage and inject the psychological paranoia
			UGameplayStatics::ApplyDamage(ActiveTarget, WarpStrikeDamage, GetController(), this, UDamageType::StaticClass());

			ACharacter* TargetChar = Cast<ACharacter>(ActiveTarget);
			if (TargetChar)
			{
				ApplyCreepingParanoia(TargetChar, 0.35f); // Initial paranoia index starts at 35%
			}
		}
	}
}

void AAshenShroudKnight::ApplyCreepingParanoia(ACharacter* TargetCharacter, float InitialIntensity)
{
	if (!TargetCharacter)
	{
		return;
	}

	// Check if player is already afflicted to stack intensity
	int32 FoundIndex = INDEX_NONE;
	for (int32 i = 0; i < ActiveParanoiaList.Num(); ++i)
	{
		if (ActiveParanoiaList[i].AfflictedActor == TargetCharacter)
		{
			FoundIndex = i;
			break;
		}
	}

	if (FoundIndex != INDEX_NONE)
	{
		// Stack the paranoia multiplier
		ActiveParanoiaList[FoundIndex].CurrentParanoiaLevel = FMath::Clamp(ActiveParanoiaList[FoundIndex].CurrentParanoiaLevel + InitialIntensity, 0.0f, 1.0f);
		ActiveParanoiaList[FoundIndex].ExpiryTime = GetWorld()->GetTimeSeconds() + 12.0f; // Refresh duration
	}
	else
	{
		FCreepingParanoiaEffect NewEffect;
		NewEffect.AfflictedActor = TargetCharacter;
		NewEffect.CurrentParanoiaLevel = InitialIntensity;
		NewEffect.AccumulatedDamageTime = 0.0f;
		NewEffect.ExpiryTime = GetWorld()->GetTimeSeconds() + 12.0f;

		ActiveParanoiaList.Add(NewEffect);
	}
}

void AAshenShroudKnight::UpdateCreepingParanoia(float DeltaTime)
{
	float CurrentTime = GetWorld()->GetTimeSeconds();

	for (int32 i = ActiveParanoiaList.Num() - 1; i >= 0; --i)
	{
		FCreepingParanoiaEffect& Effect = ActiveParanoiaList[i];
		
		if (!Effect.AfflictedActor || CurrentTime >= Effect.ExpiryTime)
		{
			// Remove effect once timer expires
			if (ACharacter* TargetChar = Cast<ACharacter>(Effect.AfflictedActor.Get()))
			{
				ClientUpdateParanoiaPostProcess(TargetChar, 0.0f);
			}
			ActiveParanoiaList.RemoveAt(i);
			continue;
		}

		// Apply Damage ticks over time scaled by paranoia intensity
		Effect.AccumulatedDamageTime += DeltaTime;
		if (Effect.AccumulatedDamageTime >= ParanoiaDoTTickRate)
		{
			ApplyDamageToAfflicted(Effect, Effect.AccumulatedDamageTime);
			Effect.AccumulatedDamageTime = 0.0f;
		}

		// Drive dynamic player screen effects
		if (ACharacter* TargetChar = Cast<ACharacter>(Effect.AfflictedActor.Get()))
		{
			ClientUpdateParanoiaPostProcess(TargetChar, Effect.CurrentParanoiaLevel);
		}
	}
}

void AAshenShroudKnight::ForceConsecratedAnchor(AActor* ConsecrationSource)
{
	if (!ConsecrationSource)
	{
		return;
	}

	// Anchor check: Rips Knight immediately from spectral or phasing states, making him physical and stun-locking him
	if (bIsPhasing)
	{
		TerminatePhaseShift(true); // Force solidification
	}

	SetAIState(EShroudKnightState::ConsecratedStun);
	GetCharacterMovement()->DisableMovement();

	// Spawn massive burst of holy embers at feet and force material to full opaque solid
	UpdateMaterialEtherealness(0.0f);

	// Apply 5-second combat stun-lock
	GetWorld()->GetTimerManager().SetTimer(StunRecoveryTimerHandle, this, &AAshenShroudKnight::RecoverFromConsecratedStun, 5.0f, false);
}

void AAshenShroudKnight::RecoverFromConsecratedStun()
{
	GetCharacterMovement()->SetDefaultMovementMode();
	SetAIState(EShroudKnightState::Stalking);
}

void AAshenShroudKnight::ApplyKaelenPinLock(float Duration)
{
	if (CurrentState == EShroudKnightState::ConsecratedStun)
	{
		// Consecration stun overrides standard pins
		return;
	}

	SetAIState(EShroudKnightState::PinnedByKaelen);
	GetCharacterMovement()->DisableMovement();

	// Prevent any attempts to phase shift
	bIsPhasing = false;
	GetCapsuleComponent()->SetCollisionProfileName(TEXT("Pawn"));
	UpdateMaterialEtherealness(0.0f);

	GetWorld()->GetTimerManager().SetTimer(PinRecoveryTimerHandle, this, &AAshenShroudKnight::RecoverFromKaelenPin, Duration, false);
}

void AAshenShroudKnight::RecoverFromKaelenPin()
{
	GetCharacterMovement()->SetDefaultMovementMode();
	SetAIState(EShroudKnightState::Stalking);
}

void AAshenShroudKnight::TriggerGarrettLure(AActor* GarrettActor)
{
	if (!GarrettActor)
	{
		return;
	}

	// Garrett utilizes positioning and decoy traps.
	// Divert boss threat index completely to focus on Garrett, breaking target on Kaelen/Serafina
	ActiveTarget = GarrettActor;
	
	// Play paranoid growl audio cues and force tracking movement
	if (CurrentState == EShroudKnightState::Idle)
	{
		SetAIState(EShroudKnightState::Stalking);
	}
}

// --- Internal Helper Implementations ---

void AAshenShroudKnight::UpdateMaterialEtherealness(float Alpha)
{
	for (UMaterialInstanceDynamic* DynMat : DynMaterials)
	{
		if (DynMat)
		{
			// Shader parameter "CorruptionAmount" drives the dither mask opacity
			DynMat->SetScalarParameterValue(TEXT("CorruptionAmount"), Alpha);
			// Dynamic emissive glow for Shroud-Knight's hollow eyes
			DynMat->SetScalarParameterValue(TEXT("EyeGlowIntensity"), Alpha > 0.0f ? 4.5f : 1.0f);
		}
	}
}

bool AAshenShroudKnight::IsOverlappingStone() const
{
	FVector ActorLocation = GetActorLocation();
	FCollisionQueryParams TraceParams(FName(TEXT("StoneCheck")), true, this);
	
	// Trace capsule volume check to ensure we don't solidify directly inside stone mesh
	TArray<FOverlapResult> Overlaps;
	FCollisionShape CapsuleShape = FCollisionShape::MakeCapsule(40.0f, 90.0f);

	// Query Stone channel specifically
	bool bHasOverlap = GetWorld()->OverlapMultiByProfile(
		Overlaps,
		ActorLocation,
		FQuat::Identity,
		TEXT("Stone"),
		CapsuleShape,
		TraceParams
	);

	return bHasOverlap;
}

void AAshenShroudKnight::ApplyDamageToAfflicted(FCreepingParanoiaEffect& Effect, float DeltaTime)
{
	if (Effect.AfflictedActor)
	{
		float CalculatedDamage = ParanoiaDamagePerTick * Effect.CurrentParanoiaLevel;
		UGameplayStatics::ApplyDamage(
			Effect.AfflictedActor,
			CalculatedDamage,
			GetController(),
			this,
			UDamageType::StaticClass()
		);
	}
}

void AAshenShroudKnight::ClientUpdateParanoiaPostProcess(ACharacter* Target, float Intensity)
{
	if (!Target)
	{
		return;
	}

	APlayerController* PC = Cast<APlayerController>(Target->GetController());
	if (PC && PC->IsLocalPlayerController())
	{
		// Drives vignette distortion & chromatic aberration on player HUD
	}
}
