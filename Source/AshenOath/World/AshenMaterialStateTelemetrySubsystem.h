// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenMaterialStateTelemetrySubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnMaterialTelemetryUpdated, FName, ParameterName, float, ScalarValue, FLinearColor, VectorValue);

/**
 * UAshenMaterialStateTelemetrySubsystem
 * Subsystem broadcasting PBR material stress, blood splatters, and oil sheen across character models.
 */
UCLASS()
class ASHENOATH_API UAshenMaterialStateTelemetrySubsystem : public UWorldSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UPROPERTY(BlueprintAssignable, Category = "Ashen Oath | Material Telemetry")
	FOnMaterialTelemetryUpdated OnMaterialTelemetryUpdated;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Material Telemetry")
	void BroadcastMaterialParameter(FName ParamName, float ScalarVal, FLinearColor VectorVal);
};
