// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Narrative/AshenJournalTypes.h"
#include "AAshenForensicCampfireActor.generated.h"

class USphereComponent;

/**
 * AAshenForensicCampfireActor
 * 
 * Spatial world actor representing the campfire chronicle rest site where party members open the forensic journal.
 */
UCLASS()
class ASHENOATH_API AAshenForensicCampfireActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenForensicCampfireActor();

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintPure, Category = "Ashen|Journal|World")
	float GetCampfireWarmthRadiusUU() const { return CampfireWarmthRadiusUU; }

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USceneComponent* SceneRoot;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USphereComponent* WarmthZone;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Journal")
	float CampfireWarmthRadiusUU = 600.0f;
};
