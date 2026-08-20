// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenMapWorldviewOverlayController.generated.h"

/**
 * UAshenMapWorldviewOverlayController
 * Controller executing Pass #4 (Worldview Overlays) — applying subjective companion marginalia (Kaelen/Garrett/Serafina) and PBR dynamic parchment shader overlays.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenMapWorldviewOverlayController : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenMapWorldviewOverlayController();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Map Pass")
	FName ActiveWorldviewAuthor = "Kaelen";

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Map Pass")
	bool RenderWorldviewOverlayPass(FName AuthorName);
};
