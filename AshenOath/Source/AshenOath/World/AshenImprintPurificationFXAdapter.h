// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenImprintPurificationFXAdapter.generated.h"

/**
 * UAshenImprintPurificationFXAdapter
 * Visual adapter managing ember dissolving VFX on purified imprints.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenImprintPurificationFXAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenImprintPurificationFXAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Visuals")
	void TriggerImprintEmberDissolve(int32 ImprintIndex);
};
