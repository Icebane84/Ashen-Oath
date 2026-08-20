// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Soul/AshenPsychicStrainTypes.h"
#include "AshenNightmareMasterBridge.generated.h"

/**
 * UAshenNightmareMasterBridge
 * Master domain bridge broadcasting incursion triggers, rift closures, and transference cascade shifts across domain subsystems.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenNightmareMasterBridge : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenNightmareMasterBridge();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Orchestration")
	bool bNightmareBridgeActive = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	void BroadcastIncursionState(bool bActive, float Intensity);

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	void BroadcastRiftSealed(FName RiftID);
};
