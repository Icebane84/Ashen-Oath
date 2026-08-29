// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Narrative/AshenForensicMindscapeTypes.h"
#include "AAshenForensicCrimeSceneWorldActor.generated.h"

/**
 * AAshenForensicCrimeSceneWorldActor
 * 
 * Interactive crime scene actor (desecrated shrine, slaughtered knight corpse, alchemical pool) yielding forensic clues when scanned with White Flame.
 */
UCLASS()
class ASHENOATH_API AAshenForensicCrimeSceneWorldActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenForensicCrimeSceneWorldActor();

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen|Forensic|World")
	void InspectScene();

	UFUNCTION(BlueprintPure, Category = "Ashen|Forensic|World")
	bool IsInspected() const { return bIsInspected; }

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USceneComponent* SceneRoot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Forensic|World")
	FName SceneClueId = TEXT("Clue_Autopsy_CorruptedKnight_01");

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Forensic|World")
	EForensicClueCategory ClueCategory = EForensicClueCategory::PhysicalAutopsyEvidence;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Forensic|World")
	FText ClueTitle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Forensic|World")
	FText ClueDescription;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|Forensic|World")
	bool bIsInspected = false;
};
