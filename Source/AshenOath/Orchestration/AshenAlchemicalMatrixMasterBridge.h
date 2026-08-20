// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenAlchemicalFormulationTypes.h"
#include "AshenAlchemicalMatrixMasterBridge.generated.h"

/**
 * UAshenAlchemicalMatrixMasterBridge
 * Master domain bridge linking Garrett's alchemical reagent inventory, trap seeding geometry, and combat abilities.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenAlchemicalMatrixMasterBridge : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenAlchemicalMatrixMasterBridge();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Orchestration")
	bool bAlchemicalBridgeActive = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	void BroadcastMatrixDeployed(EAlchemicalMatrixType Type);
};
