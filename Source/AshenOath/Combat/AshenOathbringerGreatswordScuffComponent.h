// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenOathbringerGreatswordScuffComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnOathbringerScuffUpdatedSignature, float, ScuffWearPercent, float, MetallicReflectionRoughness);

/**
 * UAshenOathbringerGreatswordScuffComponent
 *
 * Component managing dynamic physical surface scuffs, scratches, and battle wear on Kaelen's Oathbringer Greatsword (PRS-001 Oathbringer Slice).
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenOathbringerGreatswordScuffComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenOathbringerGreatswordScuffComponent();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|OathbringerScuff")
	void ApplyCombatScuffWear(float WearDelta = 5.0f);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|OathbringerScuff|Events")
	FOnOathbringerScuffUpdatedSignature OnScuffUpdated;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|OathbringerScuff")
	float ActiveScuffWearPercent = 0.0f;
};
