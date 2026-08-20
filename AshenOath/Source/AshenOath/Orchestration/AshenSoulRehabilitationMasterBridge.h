// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenSoulRehabilitationMasterBridge.generated.h"

/**
 * UAshenSoulRehabilitationMasterBridge
 * Master bridge broadcasting rehabilitation events across domain adapters.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSoulRehabilitationMasterBridge : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenSoulRehabilitationMasterBridge();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Orchestration")
	bool bRehabilitationBridgeActive = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	void BroadcastRehabilitationPulse(float IdentityPurityScore);
};
