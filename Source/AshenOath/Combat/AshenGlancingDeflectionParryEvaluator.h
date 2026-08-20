// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AshenGlancingDeflectionParryEvaluator.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnParryWindowEvaluatedSignature, int32, FinalFrameWindow, bool, bIsUnbrokenWiderWindowApplied);

/**
 * UAshenGlancingDeflectionParryEvaluator
 *
 * Evaluator computing perfect parry frame timing windows (+2 to +3 frames under Unbroken).
 */
UCLASS(BlueprintType)
class ASHENOATH_API UAshenGlancingDeflectionParryEvaluator : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|GlancingDeflection")
	int32 EvaluateParryWindowFrames(int32 BaseFrames, bool bIsUnbrokenActive);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|GlancingDeflection|Events")
	FOnParryWindowEvaluatedSignature OnParryWindowEvaluated;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|GlancingDeflection")
	int32 ActiveFrameWindow = 6;
};
