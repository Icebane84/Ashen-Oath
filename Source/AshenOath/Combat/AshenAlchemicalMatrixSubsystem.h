// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Combat/AshenAlchemicalFormulationTypes.h"
#include "AshenAlchemicalMatrixSubsystem.generated.h"

/**
 * UAshenAlchemicalMatrixSubsystem
 * GameInstance Subsystem managing Garrett's finite alchemical reagent inventory and formula compounding.
 */
UCLASS()
class ASHENOATH_API UAshenAlchemicalMatrixSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Alchemy")
	FAlchemicalInventoryPouch GarrettPouch;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Alchemy")
	bool CraftAlchemicalMatrix(EAlchemicalMatrixType Type, int32 Quantity);

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Alchemy")
	bool ConsumeAlchemicalMatrix(EAlchemicalMatrixType Type);
};
