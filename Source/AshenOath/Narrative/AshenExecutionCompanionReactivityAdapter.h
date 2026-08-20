// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenExecutionCompanionReactivityAdapter.generated.h"

/**
 * UAshenExecutionCompanionReactivityAdapter
 * Component generating companion approval imprints (+0.03) when executing dangerous foes.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenExecutionCompanionReactivityAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenExecutionCompanionReactivityAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Narrative")
	void NotifyCompanionOfExecutionFinisher(FName FoeType);
};
