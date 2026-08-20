// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenCognitiveAIMasterBridge.generated.h"

/**
 * UAshenCognitiveAIMasterBridge
 * Orchestration component bridging Cognitive AI state transitions across domain adapters.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCognitiveAIMasterBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenCognitiveAIMasterBridge();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Orchestration")
	bool bCognitiveBridgeActive = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	void BroadcastCognitiveStatePulse();
};
