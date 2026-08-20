// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_CampBehaviorInspector.generated.h"

/**
 * UAshenUserWidget_CampBehaviorInspector
 *
 * UMG backing widget for Camp Behavior Inspection ("How are we doing?").
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_CampBehaviorInspector : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	void InspectCampfireCompanions(FName GarrettState, FName SerafinaState, float PartyMoraleLevel);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	FName ActiveGarrettState;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	FName ActiveSerafinaState;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	float ActivePartyMoraleLevel = 1.0f;
};
