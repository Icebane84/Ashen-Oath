// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "AshenBlightGhoul.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/CapsuleComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "TimerManager.h"

AAshenBlightGhoul::AAshenBlightGhoul()
{
	PrimaryActorTick.bCanEverTick = true;

	GetCapsuleComponent()->InitCapsuleSize(35.0f, 72.0f);
	GetCapsuleComponent()->SetCollisionProfileName(TEXT("Pawn"));

	// Fast skittering ice-surface swarmer
	GetCharacterMovement()->MaxWalkSpeed = 600.0f;
	GetCharacterMovement()->bOrientRotationToMovement = true;

	CurrentState = EBlightGhoulState::Skittering;

	// --- Trauma Matrix: PAA V2.1 Tier I — "Preparation is an illusion" (targets Garrett) ---
	TraumaMatrix = CreateDefaultSubobject<UAshenTraumaMatrixComponent>(TEXT("TraumaMatrix"));
	TraumaMatrix->TargetVector = EAshenOathCompanion::Garrett;
	TraumaMatrix->AdversarialArgument = TEXT("Preparation is an illusion");
	TraumaMatrix->DisruptionMultiplier = 1.2f; // Tier I pressure multiplier
}

void AAshenBlightGhoul::BeginPlay()
{
	Super::BeginPlay();
}

void AAshenBlightGhoul::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AAshenBlightGhoul::SetGhoulState(EBlightGhoulState NewState)
{
	CurrentState = NewState;
}

void AAshenBlightGhoul::ExecuteClawSwipe(AActor* TargetActor, int32 NearbyGhoulCount)
{
	if (!TargetActor || CurrentState == EBlightGhoulState::Recoiling)
	{
		return;
	}

	SetGhoulState(EBlightGhoulState::ClawSwiping);

	float Distance = FVector::Dist(GetActorLocation(), TargetActor->GetActorLocation());
	if (Distance > ClawRange)
	{
		SetGhoulState(EBlightGhoulState::Skittering);
		return;
	}

	// Apply flocking bonus — if horde threshold met, multiply raw damage
	float FinalDamage = ClawDamage;
	if (NearbyGhoulCount >= FlockThreshold)
	{
		FinalDamage *= FlockBonusDamageMultiplier;
		SetGhoulState(EBlightGhoulState::FlockPressing);
		UE_LOG(LogTemp, Log, TEXT("AAshenBlightGhoul: FLOCK PRESSURE active (%d Ghouls) — damage x%.1f = %.1f"),
			NearbyGhoulCount, FlockBonusDamageMultiplier, FinalDamage);
	}

	UGameplayStatics::ApplyDamage(TargetActor, FinalDamage, GetController(), this, UDamageType::StaticClass());

	// Evaluate trauma disruption via the PAA V2.1 trauma matrix
	TraumaMatrix->EvaluateTraumaDisruption(TargetActor);

	SetGhoulState(EBlightGhoulState::Skittering);
}

void AAshenBlightGhoul::TriggerRecoilStagger()
{
	if (CurrentState == EBlightGhoulState::Recoiling)
	{
		return;
	}

	SetGhoulState(EBlightGhoulState::Recoiling);
	GetCharacterMovement()->DisableMovement();
	UE_LOG(LogTemp, Warning, TEXT("AAshenBlightGhoul: RECOIL STAGGER! Tripwire or consecrated surface hit."));

	GetWorld()->GetTimerManager().SetTimer(RecoilTimerHandle, this, &AAshenBlightGhoul::RecoverFromRecoil, 1.5f, false);
}

void AAshenBlightGhoul::RecoverFromRecoil()
{
	GetCharacterMovement()->SetDefaultMovementMode();
	SetGhoulState(EBlightGhoulState::Skittering);
	UE_LOG(LogTemp, Log, TEXT("AAshenBlightGhoul: Recovered from recoil stagger. Resuming skitter."));
}
