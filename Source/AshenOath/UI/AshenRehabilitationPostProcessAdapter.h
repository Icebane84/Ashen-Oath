// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenRehabilitationPostProcessAdapter.generated.h"

/**
 * UAshenRehabilitationPostProcessAdapter
 * Post-process adapter driving serene golden bloom during chamber activation.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenRehabilitationPostProcessAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenRehabilitationPostProcessAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Visuals")
	void ApplyGoldenRehabilitationBloom(bool bActive);
};
