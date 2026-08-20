// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenGarrettShadowStepStealthComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnShadowStepExecutedSignature, FVector, RelocationLocation, bool, bThreatDropped);

/**
 * UAshenGarrettShadowStepStealthComponent
 *
 * Component managing Garrett's shadow-step relocation and threat drop (PRS-001 Garrett Slice).
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenGarrettShadowStepStealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenGarrettShadowStepStealthComponent();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|GarrettShadowStep")
	void ExecuteShadowStep(FVector TargetStealthPosition);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|GarrettShadowStep|Events")
	FOnShadowStepExecutedSignature OnShadowStepExecuted;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|GarrettShadowStep")
	bool bIsStealthed = false;
};
