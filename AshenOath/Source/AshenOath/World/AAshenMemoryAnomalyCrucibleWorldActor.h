// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Narrative/AshenCSEQuestBoardTypes.h"
#include "AAshenMemoryAnomalyCrucibleWorldActor.generated.h"

/**
 * AAshenMemoryAnomalyCrucibleWorldActor
 * 
 * Spatial memory crucible actor spawned on the world map during high dissonance (D > 0.75), containing a phantom battle anomaly to purge.
 */
UCLASS()
class ASHENOATH_API AAshenMemoryAnomalyCrucibleWorldActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenMemoryAnomalyCrucibleWorldActor();

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintPure, Category = "Ashen|World|CSE")
	FName GetAssociatedContractId() const { return AssociatedContractId; }

	UFUNCTION(BlueprintPure, Category = "Ashen|World|CSE")
	float GetAnomalyRadiusUU() const { return AnomalyRadiusUU; }

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USceneComponent* SceneRoot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|World|CSE")
	FName AssociatedContractId = TEXT("Contract_Anomaly_01");

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|World|CSE")
	float AnomalyRadiusUU = 800.0f;
};
