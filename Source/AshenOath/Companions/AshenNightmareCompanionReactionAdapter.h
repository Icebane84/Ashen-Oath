// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Soul/AshenPsychicStrainTypes.h"
#include "AshenNightmareCompanionReactionAdapter.generated.h"

/**
 * UAshenNightmareCompanionReactionAdapter
 * Adapts companion behavior during incursions (Garrett assumes shield stance, Serafina channels focus barrier) and modulates fear barks.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenNightmareCompanionReactionAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenNightmareCompanionReactionAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Companions")
	FName EvaluateDefensiveStance(FName CompanionID, float IncursionIntensity, ETransferenceStrainStage StrainStage);
};
