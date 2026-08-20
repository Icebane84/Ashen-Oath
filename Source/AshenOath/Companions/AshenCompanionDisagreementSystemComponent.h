// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenSoulStateVectorComponent.h"
#include "AshenCompanionDisagreementSystemComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnCompanionInterpretationSignature, FName, CompanionID, FString, InterpretationText, float, ConcernLevel);

/**
 * UAshenCompanionDisagreementSystemComponent
 *
 * Component permitting Garrett and Serafina to independently interpret and react differently to Kaelen's current Soul State Vector.
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCompanionDisagreementSystemComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenCompanionDisagreementSystemComponent();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|CompanionDisagreement")
	void EvaluateCompanionInterpretations(const FAshenSoulStateVector& SoulVector);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|CompanionDisagreement|Events")
	FOnCompanionInterpretationSignature OnCompanionInterpretation;
};


