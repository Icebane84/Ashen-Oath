// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenEmpathicNovaTypes.h"
#include "AshenNovaMasterBridge.generated.h"

/**
 * UAshenNovaMasterBridge
 * Master domain bridge broadcasting Nova initiation, trigger friction telemetry, and global subsystem invalidation pulses across subsystems.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenNovaMasterBridge : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenNovaMasterBridge();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Orchestration")
	bool bNovaBridgeActive = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	void BroadcastNovaTriggered(float MutualTrust, float NovaDamage);

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	void BroadcastSubsystemsInvalidated();
};
