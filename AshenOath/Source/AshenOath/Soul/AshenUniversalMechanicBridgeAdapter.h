// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenUniversalMechanicBridgeAdapter.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnUMBBridgeMappedSignature, FName, UMBModelID, FName, TargetSystem, bool, bIsAdapterActive);

/**
 * UAshenUniversalMechanicBridgeAdapter
 *
 * UMB Adapter mapping UMB-COSM-001, UMB-GAME-001, UMB-NARR-001 models into C++ combat resolution loops.
 */
UCLASS()
class ASHENOATH_API UAshenUniversalMechanicBridgeAdapter : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|UMBAdapter")
	void MapUMBModelToSystem(FName UMBModelID, FName TargetSystem);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|UMBAdapter|Events")
	FOnUMBBridgeMappedSignature OnUMBMapped;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UMBAdapter")
	int32 TotalUMBMappingsActive = 0;
};
