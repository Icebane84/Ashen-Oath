// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenEldrinMemoryDuelTransitionComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMemoryDuelArenaTransitionStarted, FVector, ArenaCenter);

/**
 * UAshenEldrinMemoryDuelTransitionComponent
 * Manages cinematic phase transition into the Mindscape arena during Eldrin's Memory Duel.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenEldrinMemoryDuelTransitionComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenEldrinMemoryDuelTransitionComponent();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintAssignable, Category = "Ashen Oath | Memory Duel")
	FOnMemoryDuelArenaTransitionStarted OnMemoryDuelTransitionStarted;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Memory Duel")
	bool bIsInMindscapeArena = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Memory Duel")
	bool InitiateMemoryDuelTransition(FVector MindscapeArenaLocation);
};
