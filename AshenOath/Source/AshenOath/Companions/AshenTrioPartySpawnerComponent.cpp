// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Companions/AshenTrioPartySpawnerComponent.h"
#include "Companions/AshenSerafinaCompanionCharacter.h"
#include "Companions/AshenGarrettCompanionCharacter.h"
#include "Engine/World.h"

UAshenTrioPartySpawnerComponent::UAshenTrioPartySpawnerComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	SerafinaClass = AAshenSerafinaCompanionCharacter::StaticClass();
	GarrettClass = AAshenGarrettCompanionCharacter::StaticClass();
	SpawnedSerafina = nullptr;
	SpawnedGarrett = nullptr;
}

void UAshenTrioPartySpawnerComponent::BeginPlay()
{
	Super::BeginPlay();
	SpawnTrioCompanions();
}

bool UAshenTrioPartySpawnerComponent::SpawnTrioCompanions()
{
	AActor* OwnerActor = GetOwner();
	UWorld* World = GetWorld();
	if (!OwnerActor || !World) return false;

	const FVector OwnerLoc = OwnerActor->GetActorLocation();
	const FVector RightVec = OwnerActor->GetActorRightVector();

	// Spawn Serafina on Left Flank (-200 uu)
	if (SerafinaClass && !SpawnedSerafina)
	{
		const FVector SerafinaLoc = OwnerLoc - (RightVec * 200.0f);
		FActorSpawnParameters SpawnParams;
		SpawnParams.Owner = OwnerActor;
		SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

		SpawnedSerafina = World->SpawnActor<AAshenSerafinaCompanionCharacter>(SerafinaClass, SerafinaLoc, OwnerActor->GetActorRotation(), SpawnParams);
		if (SpawnedSerafina)
		{
			UE_LOG(LogTemp, Warning, TEXT("UAshenTrioPartySpawnerComponent: Successfully spawned Serafina on Left Flank!"));
		}
	}

	// Spawn Garrett on Right Flank (+200 uu)
	if (GarrettClass && !SpawnedGarrett)
	{
		const FVector GarrettLoc = OwnerLoc + (RightVec * 200.0f);
		FActorSpawnParameters SpawnParams;
		SpawnParams.Owner = OwnerActor;
		SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

		SpawnedGarrett = World->SpawnActor<AAshenGarrettCompanionCharacter>(GarrettClass, GarrettLoc, OwnerActor->GetActorRotation(), SpawnParams);
		if (SpawnedGarrett)
		{
			UE_LOG(LogTemp, Warning, TEXT("UAshenTrioPartySpawnerComponent: Successfully spawned Garrett on Right Flank!"));
		}
	}

	return (SpawnedSerafina != nullptr && SpawnedGarrett != nullptr);
}
