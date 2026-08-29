// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "World/AshenSanctuarySurvivalTypes.h"
#include "AAshenSanctuaryBeaconHearthWorldActor.generated.h"

/**
 * AAshenSanctuaryBeaconHearthWorldActor
 * 
 * Interactive ruined Sanctuary Beacon actor in the overland. When channeled with White Flame, ignites into a 1200uu warm haven sphere and logs forensic journal entries.
 */
UCLASS()
class ASHENOATH_API AAshenSanctuaryBeaconHearthWorldActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenSanctuaryBeaconHearthWorldActor();

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen|World|Sanctuary")
	void IgniteBeacon();

	UFUNCTION(BlueprintPure, Category = "Ashen|World|Sanctuary")
	bool IsIgnited() const { return bIsIgnited; }

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USceneComponent* SceneRoot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|World|Sanctuary")
	FName BeaconId = TEXT("Beacon_Gloomwood_01");

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|World|Sanctuary")
	FString RegionName = TEXT("Gloomwood Spires");

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|World|Sanctuary")
	bool bIsIgnited = false;
};
