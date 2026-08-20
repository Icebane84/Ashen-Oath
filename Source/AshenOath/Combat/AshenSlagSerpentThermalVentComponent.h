// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenSlagSerpentThermalVentComponent.generated.h"

/**
 * UAshenSlagSerpentThermalVentComponent
 * Component managing basalt rock plate brittleness, cryo-quench temperature drops, and heart chamber piercing.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSlagSerpentThermalVentComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenSlagSerpentThermalVentComponent();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Slag Serpent")
	bool bIsVentCarapaceCracked = false;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Slag Serpent")
	float InternalFurnaceTemp = 1000.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Slag Serpent")
	void ApplyCryoQuench();

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Slag Serpent")
	void ExtinguishFurnaceHeart();
};
