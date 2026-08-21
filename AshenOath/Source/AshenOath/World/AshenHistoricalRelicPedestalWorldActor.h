// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Archive/AshenCodexArchiveTypes.h"
#include "AshenHistoricalRelicPedestalWorldActor.generated.h"

class UStaticMeshComponent;

/**
 * AAshenHistoricalRelicPedestalWorldActor
 * 
 * Interactive world pedestal holding an inspectable lore relic.
 */
UCLASS()
class ASHENOATH_API AAshenHistoricalRelicPedestalWorldActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenHistoricalRelicPedestalWorldActor();

	virtual void BeginPlay() override;

	/** Interacts with pedestal to begin 3D examination */
	UFUNCTION(BlueprintCallable, Category = "Ashen|World|Archive")
	void InspectRelic();

	UFUNCTION(BlueprintPure, Category = "Ashen|World|Archive")
	FName GetRelicId() const { return RelicId; }

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USceneComponent* SceneRoot;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* PedestalMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* RelicMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|World|Archive")
	FName RelicId = FName(TEXT("Relic_Pyre_Censer"));

private:
	bool bIsInspected = false;
};
