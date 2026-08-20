// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Soul/AshenSoulConstellationTypes.h"
#include "AshenUserWidget_SoulConstellationDashboard.generated.h"

/**
 * UAshenUserWidget_SoulConstellationDashboard
 * UMG backing widget visualising the live FSoulStateVector, FBehavioralProfile, and IntegrationDebt stage.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_SoulConstellationDashboard : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	FAshenIdentityStateVector DisplayedStateVector;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void RefreshSoulConstellationDashboard(FAshenIdentityStateVector StateVector);
};

