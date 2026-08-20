// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenTrialOfWillPostProcessAdapter.generated.h"

/**
 * UAshenTrialOfWillPostProcessAdapter
 * Modulates dynamic radial blur, desaturation, and temporal chromatic aberration during the 0.75s Trial of Will time dilation.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenTrialOfWillPostProcessAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenTrialOfWillPostProcessAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Visuals")
	void ApplyStaggerDilationPostProcess(bool bActive);
};
