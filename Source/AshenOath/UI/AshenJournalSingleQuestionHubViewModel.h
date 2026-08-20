// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Soul/AshenSoulStateVector.h"
#include "AshenJournalSingleQuestionHubViewModel.generated.h"

USTRUCT(BlueprintType)
struct ASHENOATH_API FAshenPsychologicalOSQualitativeSummary
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "Qualitative Summary")
	FText MindStateDescription;

	UPROPERTY(BlueprintReadOnly, Category = "Qualitative Summary")
	FText CharacterStanceDescription;

	UPROPERTY(BlueprintReadOnly, Category = "Qualitative Summary")
	FText RelationalAnchorDescription;

	UPROPERTY(BlueprintReadOnly, Category = "Qualitative Summary")
	FText TacticalSynergyDescription;
};

UCLASS(BlueprintType)
class ASHENOATH_API UAshenJournalSingleQuestionHubViewModel : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void TranslateStateVectorToQualitativeSummary(const FSoulStateVector& StateVector);

	UFUNCTION(BlueprintPure, Category = "Ashen Oath | UI")
	const FAshenPsychologicalOSQualitativeSummary& GetQualitativeSummary() const { return CachedSummary; }

private:
	UPROPERTY()
	FAshenPsychologicalOSQualitativeSummary CachedSummary;
};
