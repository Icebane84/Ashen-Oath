// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenSerafinaMasterBridge.generated.h"

/**
 * UAshenSerafinaMasterBridge
 * Master bridge broadcasting transference and burnout events across domain adapters.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSerafinaMasterBridge : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenSerafinaMasterBridge();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Orchestration")
	bool bSerafinaBridgeActive = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	void BroadcastTransferencePulse(float HealedAmount, float BurnoutToll);
};
