// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenWhisperingWindEmitterComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnWhisperEmittedSignature, FName, DialogueCueID, float, PitchShift);

/**
 * UAshenWhisperingWindEmitterComponent
 *
 * Component broadcasting diegetic whispering wind audio cues.
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenWhisperingWindEmitterComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenWhisperingWindEmitterComponent();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|WhisperingWind")
	void EmitWhisperCue(FName DialogueCueID, float PitchShift = 1.0f);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|WhisperingWind|Events")
	FOnWhisperEmittedSignature OnWhisperEmitted;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|WhisperingWind")
	int32 TotalWhispersEmitted = 0;
};
