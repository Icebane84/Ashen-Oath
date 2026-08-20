// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AI/AshenTraumaEnemyMatrixTypes.h"
#include "AshenTraumaMasterBridge.generated.h"

/**
 * UAshenTraumaMasterBridge
 * Master domain bridge broadcasting circuit breaker trip events, tripartite resource depletion, and forced mindscape triggers across subsystems.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenTraumaMasterBridge : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenTraumaMasterBridge();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Orchestration")
	bool bTraumaBridgeActive = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	void BroadcastCircuitBreakerTripped(FName TargetHero, float UtilityScore);

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	void BroadcastForcedMindscapeTriggered();
};
