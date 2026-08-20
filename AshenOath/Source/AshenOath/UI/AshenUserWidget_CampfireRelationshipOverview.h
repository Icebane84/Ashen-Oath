// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_CampfireRelationshipOverview.generated.h"

UCLASS(Abstract)
class ASHENOATH_API UAshenUserWidget_CampfireRelationshipOverview : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void UpdateCompanionTrustLevels(float InGarrettTrust, float InSerafinaTrust);

	UFUNCTION(BlueprintPure, Category = "Ashen Oath | UI")
	float GetGarrettTrustDisplay() const { return GarrettTrustDisplay; }

	UFUNCTION(BlueprintPure, Category = "Ashen Oath | UI")
	float GetSerafinaTrustDisplay() const { return SerafinaTrustDisplay; }

private:
	float GarrettTrustDisplay = 0.5f;
	float SerafinaTrustDisplay = 0.5f;
};
