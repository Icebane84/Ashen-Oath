// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Archive/AshenCodexArchiveTypes.h"
#include "AshenCodexMasterBridge.generated.h"

/**
 * UAshenCodexMasterBridge
 * 
 * Master orchestrator connecting codex UI, 3D relic examination, audio chimes,
 * and companion dialogue triggers.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCodexMasterBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenCodexMasterBridge();

	/** Broadcasts codex repository visibility */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Orchestration|Archive")
	void BroadcastCodexVisibility(bool bIsVisible);

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Orchestration|Archive")
	FOnCodexRepositoryVisibilityChanged OnCodexRepositoryVisibilityChanged;
};
