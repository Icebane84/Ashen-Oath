// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenBlackwoodCorruptedMistVolumeComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnCorruptedMistAppliedSignature, float, MistDensityPercent, float, VisibilityPenalty);

/**
 * UAshenBlackwoodCorruptedMistVolumeComponent
 *
 * Component applying dark fog and visibility penalties around Blackwood Bridge (Where Light Fades Act 01).
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenBlackwoodCorruptedMistVolumeComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenBlackwoodCorruptedMistVolumeComponent();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|CorruptedMist")
	void UpdateMistDensity(float NewDensityPercent = 80.0f);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|CorruptedMist|Events")
	FOnCorruptedMistAppliedSignature OnMistUpdated;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|CorruptedMist")
	float ActiveMistDensity = 80.0f;
};
