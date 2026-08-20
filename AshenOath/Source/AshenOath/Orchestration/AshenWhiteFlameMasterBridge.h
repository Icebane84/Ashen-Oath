// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenWhiteFlameTypes.h"
#include "AshenWhiteFlameMasterBridge.generated.h"

/**
 * UAshenWhiteFlameMasterBridge
 * Master domain bridge linking FSoulStateVector thresholds with White Flame GAS execution, audio swells, and weapon rendering.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenWhiteFlameMasterBridge : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenWhiteFlameMasterBridge();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Orchestration")
	bool bWhiteFlameBridgeActive = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	void BroadcastWhiteFlameInvoked(float ClearedDebt);
};
