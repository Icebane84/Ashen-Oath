// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenTacticalFormationMasterBridge.generated.h"

/**
 * UAshenTacticalFormationMasterBridge
 * Orchestration component bridging companion formation states with SoulState vector updates.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenTacticalFormationMasterBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenTacticalFormationMasterBridge();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Orchestration")
	bool bFormationBridgeActive = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	void SynchronizeFormationStateVector();
};
