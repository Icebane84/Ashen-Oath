// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenRehabilitationCompanionReactivityAdapter.generated.h"

/**
 * UAshenRehabilitationCompanionReactivityAdapter
 * Component playing companion dialogue reflections when Kaelen achieves high identity purity.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenRehabilitationCompanionReactivityAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenRehabilitationCompanionReactivityAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Narrative")
	void TriggerCompanionReflectionForPurity(float IdentityPurityScore);
};
