// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenDialoguePostProcessFilterAdapter.generated.h"

/**
 * UAshenDialoguePostProcessFilterAdapter
 * Adapter driving vignette shifts during deep empathic conversations.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDialoguePostProcessFilterAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenDialoguePostProcessFilterAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void ApplyEmpathicDialogueVignette(bool bActive);
};
