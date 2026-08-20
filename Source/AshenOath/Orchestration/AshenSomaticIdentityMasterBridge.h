// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenSomaticIdentityMasterBridge.generated.h"

/**
 * UAshenSomaticIdentityMasterBridge
 * Orchestration component bridging somatic identity state transitions across domain adapters.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSomaticIdentityMasterBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenSomaticIdentityMasterBridge();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Orchestration")
	bool bIdentityBridgeActive = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	void BroadcastIdentityStatePulse();
};
