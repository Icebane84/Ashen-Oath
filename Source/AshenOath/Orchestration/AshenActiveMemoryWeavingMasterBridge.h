// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenMemoryWeavingTypes.h"
#include "AshenActiveMemoryWeavingMasterBridge.generated.h"

/**
 * UAshenActiveMemoryWeavingMasterBridge
 * Master domain bridge linking FSoulStateVector with active memory weaving GAS execution, DualSense trigger tension, and world geometry.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenActiveMemoryWeavingMasterBridge : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenActiveMemoryWeavingMasterBridge();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Orchestration")
	bool bWeavingBridgeActive = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	void BroadcastPatternWeaved(EWeavingPatternType Pattern);
};
