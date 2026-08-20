// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "AshenPurifyingAuraComponent.h"
#include "AshenWhisperingWindSubsystem.h"
#include "Kismet/KismetSystemLibrary.h"
#include "GameFramework/Pawn.h"
#include "Engine/World.h"

UAshenPurifyingAuraComponent::UAshenPurifyingAuraComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	AuraRadius = 450.0f;
	PurifyRatePerSecond = 0.05f;
}

void UAshenPurifyingAuraComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenPurifyingAuraComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	TimerTracker += DeltaTime;
	if (TimerTracker >= 1.0f)
	{
		TimerTracker = 0.0f;
		PerformPurificationPulse();
	}
}

void UAshenPurifyingAuraComponent::PerformPurificationPulse()
{
	AActor* OwnerActor = GetOwner();
	if (!OwnerActor) return;

	UWorld* World = GetWorld();
	if (!World) return;

	TArray<AActor*> OverlappedActors;
	TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes;
	ObjectTypes.Add(UEngineTypes::ConvertToObjectType(ECC_Pawn));

	UKismetSystemLibrary::SphereOverlapActors(
		World,
		OwnerActor->GetActorLocation(),
		AuraRadius,
		ObjectTypes,
		APawn::StaticClass(),
		TArray<AActor*>(),
		OverlappedActors);

	for (AActor* Target : OverlappedActors)
	{
		if (!Target || Target == OwnerActor) continue;

		// Purify corruption via Whispering Wind subsystem
		if (UGameInstance* GI = World->GetGameInstance())
		{
			if (UAshenWhisperingWindSubsystem* Whispers = GI->GetSubsystem<UAshenWhisperingWindSubsystem>())
			{
				float CurrentIntensity = Whispers->GetWhisperIntensity();
				Whispers->SetCorruptionInput(FMath::Max(0.0f, CurrentIntensity - PurifyRatePerSecond));
			}
		}

		OnPurifyApplied.Broadcast(Target, PurifyRatePerSecond);
		UE_LOG(LogTemp, Log, TEXT("UAshenPurifyingAuraComponent: Purified -%.2f corruption for '%s'."), PurifyRatePerSecond, *Target->GetName());
	}
}
