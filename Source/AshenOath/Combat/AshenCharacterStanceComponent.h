// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenCharacterStanceComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnStanceBlendUpdatedSignature, FName, StanceTag, float, GuardBlendWeight);

/**
 * UAshenCharacterStanceComponent
 *
 * Component blending Kaelen's combat stance (Hunched Guarded vs Upright Grounded) with Soul State Resolve.
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCharacterStanceComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenCharacterStanceComponent();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Stance")
	void UpdateStanceFromResolve(float ResolveValue);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Stance|Events")
	FOnStanceBlendUpdatedSignature OnStanceUpdated;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Stance")
	FName CurrentStanceTag;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Stance")
	float GuardBlendWeight = 0.5f;
};
