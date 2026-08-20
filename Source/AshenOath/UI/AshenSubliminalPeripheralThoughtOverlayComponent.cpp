// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 819: Ashen Subliminal Peripheral Thought Overlay Component

#include "AshenSubliminalPeripheralThoughtOverlayComponent.h"

UAshenSubliminalPeripheralThoughtOverlayComponent::UAshenSubliminalPeripheralThoughtOverlayComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	TotalThoughtsFlickered = 0;
}

void UAshenSubliminalPeripheralThoughtOverlayComponent::FlickerSubliminalThought(FText ThoughtText)
{
	TotalThoughtsFlickered++;
	const float Opacity = 0.35f; // Faint 35% opacity single-frame peripheral flicker

	OnThoughtFlickered.Broadcast(ThoughtText, Opacity);

	UE_LOG(LogTemp, Warning, TEXT("UAshenSubliminalPeripheralThoughtOverlayComponent: SUBLIMINAL THOUGHT FLICKERED -> Text: '%s' | Single-Frame Opacity: %.2f (Total: %d)."),
		*ThoughtText.ToString(), Opacity, TotalThoughtsFlickered);
}
