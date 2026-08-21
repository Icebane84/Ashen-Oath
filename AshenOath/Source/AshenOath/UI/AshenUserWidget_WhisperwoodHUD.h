// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Scenarios/AshenScenario4WhisperwoodTypes.h"
#include "AshenUserWidget_WhisperwoodHUD.generated.h"

/**
 * UAshenUserWidget_WhisperwoodHUD
 * 
 * UMG HUD displaying Sanity Chromatic Aberration levels, soot layer blur, and discovered cognitive loci.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_WhisperwoodHUD : public UUserWidget
{
	GENERATED_BODY()

public:
	UAshenUserWidget_WhisperwoodHUD(const FObjectInitializer& ObjectInitializer);

	/** Updates the psychological HUD overlays */
	UFUNCTION(BlueprintCallable, Category = "Ashen|UI|Scenario4")
	void UpdatePsychologicalState(float Sanity, float SootOpacity, int32 LociCount);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Scenario4")
	float DisplayedSanity = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Scenario4")
	float DisplayedSootOpacity = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Scenario4")
	int32 DisplayedLociCount = 0;
};
