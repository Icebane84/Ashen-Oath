// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenLethalInterceptCrisisPromptActor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnCrisisPromptTriggeredSignature, FName, CrisisReason, float, TimeRemainingSeconds);

/**
 * AAshenLethalInterceptCrisisPromptActor
 *
 * World Actor triggering crisis prompts when Kaelen hits 0 HP or allies face lethal threat (PRS-001 Combat Blueprint).
 */
UCLASS()
class ASHENOATH_API AAshenLethalInterceptCrisisPromptActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenLethalInterceptCrisisPromptActor();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|CrisisPrompt")
	void TriggerCrisisPrompt(FName Reason, float TimeLimit = 3.0f);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|CrisisPrompt|Events")
	FOnCrisisPromptTriggeredSignature OnCrisisTriggered;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|CrisisPrompt")
	bool bIsPromptActive = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|CrisisPrompt")
	FName ActiveCrisisReason;
};
