// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Companions/AshenSomaticSilenceTypes.h"
#include "AshenSomaticSilenceMasterBridge.generated.h"

/**
 * UAshenSomaticSilenceMasterBridge
 * 
 * Master orchestrator connecting silence evaluation events, wordless support
 * commands, and boundary refusal broadcasts across downstream listeners.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSomaticSilenceMasterBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenSomaticSilenceMasterBridge();

	/** Broadcasts classified silence */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Orchestration|Silence")
	void BroadcastSilenceClassified(const FSilenceEvaluationSnapshot& Snapshot);

	/** Broadcasts wordless support command */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Orchestration|Silence")
	void BroadcastWordlessSupport(const FWordlessSupportCommand& Command);

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Orchestration|Silence")
	FOnSilenceClassified OnSilenceClassified;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Orchestration|Silence")
	FOnWordlessSupportDispatched OnWordlessSupportDispatched;
};
