// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Soul/AshenSoulStateVector.h"
#include "AshenQualitativeStateTranslationLibrary.generated.h"

UCLASS()
class ASHENOATH_API UAshenQualitativeStateTranslationLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category = "Ashen Oath | Soul")
	static FText GetQualitativeCorruptionDescription(float Corruption);

	UFUNCTION(BlueprintPure, Category = "Ashen Oath | Soul")
	static FText GetQualitativeResolveDescription(float Resolve);
};
