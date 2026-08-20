// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenGarrettTacticalTelemetrySaveGameAdapter.generated.h"

/**
 * UAshenGarrettTacticalTelemetrySaveGameAdapter
 * Core save adapter tracking total traps deployed and grapple rescues.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenGarrettTacticalTelemetrySaveGameAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenGarrettTacticalTelemetrySaveGameAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Core")
	bool SerializeGarrettTelemetryToSave(int32 TotalTrapsDeployed, int32 TotalGrappleRescues);
};
