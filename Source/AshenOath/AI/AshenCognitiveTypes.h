// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameplayTagContainer.h"
#include "AshenCognitiveTypes.generated.h"

USTRUCT(BlueprintType)
struct FAshenActionUtilityData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath|Cognitive")
	FGameplayTag ActionTag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath|Cognitive")
	float BaseUtility = 0.5f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath|Cognitive")
	float CalculatedUtility = 0.5f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath|Cognitive")
	int32 RecentUsageCount = 0;
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnCognitiveActionSelected, FGameplayTag, SelectedActionTag, float, UtilityValue);
