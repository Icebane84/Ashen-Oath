// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "AshenAbomination.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/CapsuleComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "TimerManager.h"

AAshenAbomination::AAshenAbomination()
{
	PrimaryActorTick.bCanEverTick = true;

	GetCapsuleComponent()->InitCapsuleSize(90.f, 180.0f);
	GetCapsuleComponent()->SetCollisionProfileName(TEXT("Pawn"));

	GetCharacterMovement()->MaxWalkSpeed = 320.0f; // Heavy lurching movement
	GetCharacterMovement()->bOrientRotationToMovement = true;

	CurrentState = EAbhenAbominationState::Idle;
	bBarkArmorIntact = true;
}

void AAshenAbomination::BeginPlay()
{
	Super::BeginPlay();
}

void AAshenAbomination::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AAshenAbomination::SetBossState(EAbhenAbominationState NewState)
{
	CurrentState = NewState;
}

void AAshenAbomination::ExecuteBoneSpurSweep(AActor* TargetActor)
{
	if (!TargetActor || CurrentState == EAbhenAbominationState::TripwireStumbled)
	{
		return;
	}

	SetBossState(EAbhenAbominationState::BoneSpurSweeping);
	UE_LOG(LogTemp, Log, TEXT("AAshenAbomination: Executing Bone Spur Sweep arc!"));

	float Distance = FVector::Dist(GetActorLocation(), TargetActor->GetActorLocation());
	if (Distance <= 450.0f)
	{
		UGameplayStatics::ApplyDamage(TargetActor, BoneSpurDamage, GetController(), this, UDamageType::StaticClass());
	}

	SetBossState(EAbhenAbominationState::Lurching);
}

void AAshenAbomination::ExecuteOverheadCrush(AActor* TargetActor)
{
	if (!TargetActor || CurrentState == EAbhenAbominationState::TripwireStumbled)
	{
		return;
	}

	SetBossState(EAbhenAbominationState::OverheadCrushing);
	UE_LOG(LogTemp, Log, TEXT("AAshenAbomination: Executing Overhead Crush smash!"));

	float Distance = FVector::Dist(GetActorLocation(), TargetActor->GetActorLocation());
	if (Distance <= 550.0f)
	{
		UGameplayStatics::ApplyDamage(TargetActor, OverheadCrushDamage, GetController(), this, UDamageType::StaticClass());
	}

	SetBossState(EAbhenAbominationState::Lurching);
}

void AAshenAbomination::OnStumbledByTripwire()
{
	SetBossState(EAbhenAbominationState::TripwireStumbled);
	GetCharacterMovement()->DisableMovement();

	UE_LOG(LogTemp, Warning, TEXT("AAshenAbomination: STUMBLED BY TRIPWIRE! Collapsed on knees for 4 seconds!"));

	GetWorld()->GetTimerManager().SetTimer(StumbleTimerHandle, this, &AAshenAbomination::RecoverFromStumble, 4.0f, false);
}

void AAshenAbomination::RecoverFromStumble()
{
	GetCharacterMovement()->SetDefaultMovementMode();
	SetBossState(EAbhenAbominationState::Lurching);
	UE_LOG(LogTemp, Log, TEXT("AAshenAbomination: Recovered from stumble. Resuming lurching attack!"));
}

void AAshenAbomination::StripBarkArmor()
{
	bBarkArmorIntact = false;
	UE_LOG(LogTemp, Log, TEXT("AAshenAbomination: Bark armor stripped by alchemical oil!"));
}
