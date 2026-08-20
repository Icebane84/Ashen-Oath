// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenWhiteFlameDualSenseHapticsComponent.generated.h"

/**
 * UAshenWhiteFlameDualSenseHapticsComponent
 * Modulates soothing rhythmic heartbeat haptics and fully releases motorized trigger friction during the White Flame Resolution state.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenWhiteFlameDualSenseHapticsComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenWhiteFlameDualSenseHapticsComponent();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Haptics")
	bool bIsSoothingHapticsActive = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Haptics")
	void TriggerCatharsisHeartbeatHaptics(bool bActive);
};
