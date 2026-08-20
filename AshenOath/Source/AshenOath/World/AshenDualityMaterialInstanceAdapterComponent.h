// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenDualityMaterialInstanceAdapterComponent.generated.h"

/**
 * UAshenDualityMaterialInstanceAdapterComponent
 * Dynamic material instance controller updating scalar and vector parameters.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDualityMaterialInstanceAdapterComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenDualityMaterialInstanceAdapterComponent();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Visuals")
	void UpdateMaterialInstanceParameters(FName ParameterName, float Value);
};
